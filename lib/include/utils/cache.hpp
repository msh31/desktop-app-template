#pragma once
#include <logger.hpp>
#include <task_runner/task_runner.hpp>

template <typename T> class CCache {
    public:
        ~CCache( ) { m_taskrunner.shutdown( ); }

        void refresh( std::function<T( )> fun ) {
            if ( m_is_refreshing ) return;

            m_is_refreshing = true;

            m_taskrunner.run<T>(
                fun,
                [this](T val) {
                    m_current_snapshot = val;
                    m_is_refreshing = false;
                    if ( m_on_updated ) m_on_updated( m_current_snapshot );
                },
                []( const std::exception& ex ) { SPDLOG_ERROR( "Cache Refresh Error: {}", ex.what( ) ); } );
        }
        const T& get( ) {
            m_taskrunner.update( );
            return m_current_snapshot;
        }
        bool is_refreshing( ) { return m_is_refreshing; }
        void seed( T val ) { m_current_snapshot = val; }
        void set_on_updated( std::function<void( const T& )> fn ) { m_on_updated = fn; }

    private:
        T m_current_snapshot = { };
        std::atomic<bool> m_is_refreshing = false;
        std::function<void( const T& )> m_on_updated;

        CTaskRunner m_taskrunner;
};

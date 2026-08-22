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
                },
                []( const std::exception& ex ) { SPDLOG_ERROR( "Cache Refresh Error: {}", ex.what( ) ); } );
        }
        const T& get( ) {
            m_taskrunner.update( );
            return m_current_snapshot;
        }
        bool is_refreshing( ) { return m_is_refreshing; }

    private:
        T m_current_snapshot = { };
        std::atomic<bool> m_is_refreshing = false;
        CTaskRunner m_taskrunner;
};

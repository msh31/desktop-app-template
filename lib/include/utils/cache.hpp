#pragma once
#include <logger.hpp>
#include <task_runner/task_runner.hpp>

template <typename T> class CCache {
    public:
        ~CCache( ) { m_taskrunner.shutdown( ); }

        void refresh( std::function<T( )> fun ) {
            if ( m_is_refreshing ) return;

            m_is_refreshing = true;
            std::shared_ptr<T> slot = std::make_shared<T>( );

            m_taskrunner.run(
                [this, slot, fun] { *slot = fun( ); },
                [this, slot] {
                    m_current_snapshot = *slot;
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

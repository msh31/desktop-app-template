#pragma once
#include <task_runner/task_runner.hpp>
#include <frontend/views/base_view.hpp>

class CDebugView : public CBaseView {
    public:
        ~CDebugView( ) override;
        void render( ) override;

    private:
        CTaskRunner m_task_runner;
};

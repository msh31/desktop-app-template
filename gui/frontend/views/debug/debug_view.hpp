#pragma once
#include <frontend/views/base_view.hpp>
#include <task_runner/task_runner.hpp>

class CDebugView : public CBaseView {
    public:
        ~CDebugView( ) override;
        void render( ) override;
        void on_exit( ) override;

    private:
        CTaskRunner m_task_runner;
        std::optional<TaskHandle> m_task_handle;

        std::ifstream m_file;
        std::string m_file_path;
        std::string m_file_size; // shown with the proper uh suffix like GB, KB etc..
        std::string m_file_name;
        bool m_is_file_open = false;
};

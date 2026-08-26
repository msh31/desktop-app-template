#pragma once
// Generic, stable C++ stdlib headers only

#ifdef __cplusplus
    #include <algorithm>
    #include <atomic>
    #include <chrono>
    #include <deque>
    #include <expected>
    #include <filesystem>
    #include <fstream>
    #include <functional>
    #include <future>
    #include <memory>
    #include <mutex>
    #include <print>
    #include <regex>
    #include <stdexcept>
    #include <string>
    #include <string_view>
    #include <thread>
    #include <unordered_set>
    #include <vector>

namespace fs = std::filesystem;
#endif

// TODO: undo this mess
#ifdef __linux__
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
#endif

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #define NOMINMAX
    #include <Psapi.h>
    #include <ShlObj_core.h>
    #include <Windows.h>
#endif
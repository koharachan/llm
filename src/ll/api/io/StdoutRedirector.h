#pragma once

#include <string>

namespace ll::io {

class StdoutRedirector {
public:
    enum ProcessChannel { StandardOutput = 1, StandardError = 2 };
#if defined(LL_WIN32)
    LLNDAPI explicit StdoutRedirector(
        void*          outputHandle,
        ProcessChannel channels = (ProcessChannel)(StandardOutput | StandardError)
    );

    LLAPI ~StdoutRedirector();

    ProcessChannel channels;
    void*          outputHandle;
#elif defined(LL_LINUX)
    StdoutRedirector(int outputFd, ProcessChannel channels);

    ~StdoutRedirector();

    ProcessChannel channels;
    int            outputFd;

private:
    int oldStdout;
    int oldStderr;
#endif
};
} // namespace ll::io

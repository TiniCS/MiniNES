#ifndef __Log_H__
#define __Log_H__

#include <iostream>
#include <string.h>

namespace mn {
    enum LogLevel {
        None,
        Error,
        Info,
        CPUTrace
    };

    class Log {
    public:
        Log(std::ostream& stream = std::cout);
        Log(std::ostream&& stream);
        void setLogLevel(LogLevel level);
        std::ostream& operator << (std::string& str);
        void setLogStream(std::ostream& stream);
    private:
        LogLevel m_logLevel;
        std::ostream* m_logStream;
    };

    extern Log logConsole;
    extern Log logCPUTrace;
    extern Log logFile;
}

#endif // !__Log_H__
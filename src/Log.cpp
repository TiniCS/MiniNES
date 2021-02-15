#include <Log.h>
#include <fstream>
namespace mn {
    std::string levelString[] = {
        "None", "Error",
        "Info",
        "CPUTrace"
    };

    Log::Log(std::ostream& stream) {
        m_logStream = &(stream);
        m_logLevel = None;
    }

    Log::Log(std::ostream&& stream) {
        m_logStream = &(stream);
        m_logLevel = None;
    }

    void Log::setLogLevel(LogLevel level){
        m_logLevel = level;
    }

    std::ostream& Log::operator<<(std::string& str) {
        (*m_logStream) << levelString[m_logLevel] << str;
        return (*m_logStream);
    }

    Log logConsole(std::cout);
    Log logCPUTrace(std::ofstream("sn.cpudump"));
    Log logFile(std::ofstream("simplenes.log"));
}
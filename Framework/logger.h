#define LOG(str, ...) logger_log(str, ##__VA_ARGS__)

typedef enum
{
    LOG_OUTPUT_POLICY_NONE = 0,
    LOG_OUTPUT_POLICY_FILE = 1,
    LOG_OUTPUT_POLICY_STDOUT = 2
} LOG_OUTPUT_POLICY;

void logger_init(LOG_OUTPUT_POLICY policy, const char *logFilePath);
void logger_log(const char *format, ...);
void logger_destroy();
char *get_time();

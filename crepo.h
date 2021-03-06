#ifndef __CREPO_H__
#define __CREPO_H__

#include <string>
#include <vector>

typedef std::string STRING;

typedef enum crepo_action {
    ACTION_UNKNOWN,
    ACTION_HELP,
    ACTION_VERSION,
    ACTION_CHECKOUT,
    ACTION_CHECKIN,
    ACTION_DIFF,
    ACTION_STAT,
    ACTION_BRANCH,
} ACTION;

struct crepo_parms {
    ACTION      eAction;
    STRING      sRepoURL;
    STRING      sRepoBranch;
    STRING      sCheckoutDir;
};

typedef bool (*ACTION_HANDLER)(const crepo_parms& parms);

struct action_dispatch_table {
    STRING          option;
    ACTION          action;
    ACTION_HANDLER  handler;
};

/**
 *  Version information.
 */

#define CREPO_APP_NAME          "crepo"
#define CREPO_MAJOR_VERSION     1
#define CREPO_MINOR_VERSION     2
#define CREPO_BUILD_DATE        __DATE__

extern const char*     szAppName;
extern const char*     szBuildDate;

#endif // __CREPO_H__


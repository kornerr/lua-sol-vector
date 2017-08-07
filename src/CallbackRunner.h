
#ifndef LUA_SOL_VECTOR_CALLBACK_RUNNER_H
#define LUA_SOL_VECTOR_CALLBACK_RUNNER_H

#include "CallbackContainer.h"

class CallbackRunner
{
    public:
        CallbackRunner() { }

        Strings call(CallbackContainer *c, const Strings &values)
        {
            return c->call(values);
        }
};

#endif // LUA_SOL_VECTOR_CALLBACK_RUNNER_H


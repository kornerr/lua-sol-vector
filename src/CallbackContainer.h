
#ifndef LUA_SOL_VECTOR_CALLBACK_CONTAINER_H
#define LUA_SOL_VECTOR_CALLBACK_CONTAINER_H

#include "Common.h"

#include <cstdio>
#include <functional>

class CallbackContainer
{
    public:
        typedef std::function<Strings (const Strings &)> Callback;
        Callback callback;

        CallbackContainer() : callback(nullptr) { }

        Strings call(const Strings &values)
        {
            if (this->callback)
            {
                return this->callback(values);
            }
            printf("CallbackContainer.call(). No callback provided!\n");
            Strings stub;
            return stub;
        }
};

#endif // LUA_SOL_VECTOR_CALLBACK_CONTAINER_H


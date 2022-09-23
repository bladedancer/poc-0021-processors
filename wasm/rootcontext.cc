#include "./rootcontext.h"
#include "proxy_wasm_intrinsics.pb.h"

bool DemoRootContext::onConfigure(size_t config_size)
{
    LOG_TRACE("onConfigure called");
    return true;
}

#ifndef __DEMOCONTEXT_H__
#define __DEMOCONTEXT_H__
#include <string>
#include <string_view>
#include <unordered_map>

#include "proxy_wasm_intrinsics.h"

#include "./rootcontext.h"

class DemoContext : public Context
{
public:
  explicit DemoContext(uint32_t id, RootContext *root) : Context(id, root) {}

  FilterHeadersStatus onRequestHeaders(uint32_t headers, bool end_of_stream) override;
  FilterDataStatus onRequestBody(size_t body_buffer_length, bool end_of_stream) override;

private:
  WasmResult initRequest();
};

static RegisterContextFactory register_DemoContext(CONTEXT_FACTORY(DemoContext),
                                                     ROOT_FACTORY(DemoRootContext),
                                                     "demoFilter");
#endif
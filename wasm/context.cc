#include "./context.h"
#include "./rootcontext.h"

FilterHeadersStatus DemoContext::onRequestHeaders(uint32_t, bool end_of_stream)
{
  LOG_TRACE(std::string("onRequestHeaders called ") + std::to_string(id())); 
  LOG_INFO("Sending headers");
  addRequestHeader(std::string("wasm-header"), std::string("worked"));
  return FilterHeadersStatus::Continue;
}

FilterDataStatus DemoContext::onRequestBody(size_t body_buffer_length, bool end_of_stream)
{
  LOG_INFO("onRequestBody");
  LOG_INFO("Sending body");
  return FilterDataStatus::Continue;
}

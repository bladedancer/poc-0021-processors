PROXY_WASM_CPP_SDK=/sdk
CPP_API:=${PROXY_WASM_CPP_SDK}
CPP_CONTEXT_LIB = ${CPP_API}/proxy_wasm_intrinsics.cc

SRC	= $(wildcard ./*.cc)

all: clean demo.wasm

demo.wasm: ${CPP_API}/proxy_wasm_intrinsics.h ${CPP_API}/proxy_wasm_enums.h ${CPP_API}/proxy_wasm_externs.h ${CPP_API}/proxy_wasm_api.h ${CPP_API}/proxy_wasm_intrinsics.js ${CPP_CONTEXT_LIB}
	echo ${SRC}
	#em++ -s EXPORTED_FUNCTIONS=['_malloc'] --std=c++17 -O3 -flto -I${CPP_API} -I${CPP_API}/google/protobuf -I/usr/local/include -I/work/proto --js-library ${CPP_API}/proxy_wasm_intrinsics.js  ${CPP_API}/proxy_wasm_intrinsics.pb.cc  ${CPP_CONTEXT_LIB} ${CPP_API}/libprotobuf.a ${SRC} -o demo.wasm
	em++ --no-entry -s EXPORTED_FUNCTIONS=['_malloc'] --std=c++17 -O3 -flto -I${CPP_API} -I${CPP_API}/google/protobuf -I/usr/local/include -I/work/proto --js-library ${CPP_API}/proxy_wasm_intrinsics.js  ${CPP_API}/proxy_wasm_intrinsics.pb.cc  ${CPP_CONTEXT_LIB} ${CPP_API}/libprotobuf.a ${SRC} -o demo.wasm

clean:
	rm -f *.o *.wasm


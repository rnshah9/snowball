#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" const char *name_of_token(int code);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)

    {
        FuzzedDataProvider provider(data, size);
        int code = provider.ConsumeIntegral<int>();

        name_of_token(code);

        return 0;
    }

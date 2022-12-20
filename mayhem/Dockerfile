FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang

COPY . /repo
WORKDIR /repo
RUN make -j8

RUN rm /repo/compiler/driver.o

RUN clang++ /repo/mayhem/fuzz_name_of_token.cpp -fsanitize=fuzzer,address /repo/compiler/*.o -o /fuzz

FROM ubuntu:22.04 as package
COPY --from=builder /repo/snowball /
COPY --from=builder /fuzz /fuzz_name_of_token

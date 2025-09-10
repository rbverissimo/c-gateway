FROM mcr.microsoft.com/devcontainers/cpp:1-bookworm AS builder

RUN sudo apt-get update && sudo apt-get install -y git cmake

WORKDIR /app

RUN git clone https://github.com/microsoft/vcpkg.git

RUN ./vcpkg/bootstrap-vcpkg.sh

COPY vcpkg.json .

RUN ./vcpkg/vcpkg install --triplet x64-linux

COPY CMakeLists.txt .

RUN vcpkg install

COPY src ./src/

RUN mkdir build

RUN cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/app/vcpkg/scripts/buildsystems/vcpkg.cmake
RUN cmake --build build

FROM debian:bookworm-slim

WORKDIR /app

COPY --from=builder /app/build/api-gateway-cpp .

EXPOSE 18080

CMD [ "./api-gateway-cpp" ]




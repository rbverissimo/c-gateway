FROM mcr.microsoft.com/devcontainers/cpp:1-bookworm AS builder

RUN sudo apt-get update && sudo apt-get install -y git cmake build-essential

WORKDIR /usrapp

RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg

RUN /opt/vcpkg/bootstrap-vcpkg.sh

COPY . .

RUN /opt/vcpkg/vcpkg install --triplet x64-linux

RUN cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake

RUN cmake --build build

FROM debian:bookworm-slim

WORKDIR /app

COPY --from=builder /app/build/api-gateway-cpp .

EXPOSE 18080

CMD [ "./api-gateway-cpp" ]




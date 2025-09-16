FROM mcr.microsoft.com/devcontainers/cpp:1-bookworm AS builder

RUN sudo apt-get update && sudo apt-get install -y git cmake build-essential

RUN mkdir vcpkg

RUN git clone https://github.com/microsoft/vcpkg.git /vcpkg

RUN /vcpkg/bootstrap-vcpkg.sh

WORKDIR /usrapp

COPY vcpkg.json . 

RUN /vcpkg/vcpkg install --triplet x64-linux

#RUN chown -R vscode:vscode /vcpkg && chmod -R u+rwX /vcpkg

COPY . .

FROM debian:bookworm-slim

WORKDIR /app

COPY --from=builder /app/build/api-gateway-cpp .

EXPOSE 18080

CMD [ "./api-gateway-cpp" ]




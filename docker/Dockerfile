
FROM ubuntu:17.10

RUN apt update && \
    apt install -y build-essential \
                   ninja-build \
                   cmake \
                   git && \
                   cd && \
                   git clone https://github.com/google/googletest.git gtest && \
                   cd gtest && \
                   mkdir build && \
                   cd build && \
                   cmake .. && \
                   cmake --build . -- -j2 && \
                   make install && \
                   cd && \
                   git clone https://github.com/google/benchmark.git gbench && \
                   cd gbench && \
                   mkdir build && \
                   cd build && \
                   cmake .. -DCMAKE_BUILD_TYPE=RELEASE -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON && \
                   cmake --build . -- -j2 && \
                   make install
                   
ADD build_script.sh /root/build_script.sh



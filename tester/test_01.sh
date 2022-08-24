#!/bin/bash

# 1. server, client build
clang ../01_now_you_see_me/server.c -o server -Werror -Wextra
clang ../00_show_me_the_cpu/client.c -o client -Werror -Wextra

chmod +x server
chmod +x client

# 2. run test in 10s
./server > server.log &
export SERVER_PID=$!
./client > client.log &
export CLIENT_PID=$!
echo $SERVER_PID
echo $CLIENT_PID
sleep 10
kill $SERVER_PID
kill $CLIENT_PID
sleep 1

diff client.log server.log

rm client*
rm server*
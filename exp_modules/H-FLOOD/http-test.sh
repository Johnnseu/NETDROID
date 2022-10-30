exec 5<>/dev/tcp/$1/$2
echo -ne "GET / HTTP/1.1\r\nHOST: $1\r\n\r\n" >&5
cat <&5

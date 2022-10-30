while :
do
exec 5<>/dev/tcp/0.0.0.0/8000
echo -ne "GET / HTTP/1.0\r\nHost: 0.0.0.0\r\nConnection: keep-alive\r\nAccept: */*\r\nAccept-Encoding: gzip, deflate\r\n\r\n" >&5
done

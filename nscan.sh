
RED='\033[0;31m'
Black='\033[0;30m'        
Red='\033[0;31m'          
Green='\033[0;32m'        
Yellow='\033[0;33m'       
Blue='\033[0;34ssxm'       
Purple='\033[0;35m'       
Cyan='\033[0;36m'         
White='\033[0;37m'        
NC='\033[0m' 

function banner() {
clear
echo " _   _      _   ____                 "
echo "| \ | | ___| |_/ ___|  ___ __ _ _ __ "
echo "|  \| |/ _ \ __\___ \ / __/ _  |  _ \ "
echo "| |\  |  __/ |_ ___) | (_| (_| | | | | "
echo "|_| \_|\___|\__|____/ \___\__,_|_| |_| "
echo ""
printf "${Yellow}Created by Johnjoe${NC}"
echo ""
}

function main() {
printf "${Green}[${NC}${Yellow}1${NC}${Green}]${NC}  ${Yellow}IP Range Scan ${NC}"
echo ""
printf "${Green}[${NC}${Yellow}2${NC}${Green}]${NC}  ${Yellow}Port Scan ${NC}"
echo ""
printf "${Green}[${NC}${Yellow}4${NC}${Green}]${NS}  ${Yellow}ReverseShell ${NC}"  
echo ""
echo ">>" && read input 
  if [ "$input" = "0" ]; then
 echo "quiting" && exit 0
 elif [ "$input" = "1" ]; then
rangescan
 elif [ "$input" = "2" ]; then
portscan
 elif [ "$input" = "4" ]; then
reverseshell
 elif [ "$input" = "exit" ]; then
exit 0
  else
echo "wrong input"
clear
main
fi
}       
  

function rangescan() {
echo "Usage :
 scan 192.168.43 <prfx> <prfx>  :  192.168.43 1 255  scans IP 192.168.43.1 to 192.168.43.255
     menu : returns to menu"
mnu
}
mnu() {
echo ">ping"
read  scan ip rmgs 
if [ "$scan" = "scan" ]; then
echo "Scan in progress, this may take some time"

range_ping() {
  ping -c 1 $1 > /dev/null
 [ $? -eq 0 ] && printf "Host : ${Red}$1${NC} is up" && echo "" 
}

oc1="$(cut -d'.' -f1 <<<"$ip")"
oc2="$(cut -d'.' -f2 <<<"$ip")"
oc3="$(cut -d'.' -f3 <<<"$ip")"
oc4="$(cut -d'.' -f4 <<<"$ip")"

rges="$(cut -d'/' -f2 <<<"$rmgs")"

for ip in $(seq $oc4 $rges); do
    range_ping $oc1.$oc2.$oc3.$ip
done
echo ""
echo "scan complete" && mnu aware
elif [ "$scan" = "menu" ]; then
main
else
echo "wrong input"
mnu
fi
}

function portscan() {
echo "Usage :
             <IP> <startport> <endport> :example 
                                         192.168.43.1 1 1024"
./a.out
echo "press c to goto main"
echo ">>"
read rdy
if [ "$rdy" = "c" ]; then
main
else 
main
fi 
}
banner
main

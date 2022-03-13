import json

with open("input.txt", "r") as f: 
    data = json.load(f) 
    print(type(data)) 
    for x in data:
        print(x) 
        print(x['name']) 

l = [{"id": 1, "name": "Adi", "test1": 7, "test2": 5}, {"id": 2, "name": "Teo", "test1": 5, "test2": 9}]
with open("output.txt", "w") as f: # open in write mode
    json.dump(l, f)


def average(in_file, out_file):
    pass




average('input.txt',"output.txt")
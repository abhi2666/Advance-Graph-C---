import pickle

lst = ["mohit", "rohit"]
f = open("file1.dat", "wb");
pickle.dump(lst, f)

f.close()
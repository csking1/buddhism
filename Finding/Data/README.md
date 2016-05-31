# File Instructions


Most of the files in this directory are text files that we're using to create our training set. Here are the running instructions we used to clean them.


1. We had to pre-process all of the files to make them more machine readable. We did it with something like this:

```
python reader.py Buddhist_to_text/one.txt 1 | tee Buddhist_to_text/Ready/one.txt
```


2. This walks through each line for each file in the Ready Directory, removes stop words and any punctuation, and sends each sentence to the main testing file. 
```
python clean_and_send_to_main_test.py
```
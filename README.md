# Malicious-URL-checker-using-Bloom-Filter-

Bloom Filter is probabilistic data structure which tells us if the value is definitely  not in the input stream or maybe in the stream .
Bloom filter consists of bit vector and hash functions.
It takes array and When you add an element, the hashing functions set the bits of the hashed index to 1.
To check whether an element maybe in the filter we use the same hash functions and see if the values are set in the bit vector.
To increase the efficiency of regular bloom filter , I have implemented this "2-level" bloom filter.

Idea of the Project

Malicious URL dataset is added into the malicious URL Bloom Filter.
The Streaming data is passed through the Bloom Filter.
If the query returns ‘0’ then the URL does not exist in the malicious URL Bloom Filter, so it is definitely  good.
If the query returns ‘1’ there is a possibility of the URL being good/bad.
To be absolutely  sure again , the URL is passed through the cross reference Bloom Filter which has maximum array size. 
If the result out of the cross-reference Bloom Filter is ‘0’ it means the URL is  safe .
If the result of the cross-reference Bloom Filter is ‘1’ it means it is false positive i.e. malicious. 





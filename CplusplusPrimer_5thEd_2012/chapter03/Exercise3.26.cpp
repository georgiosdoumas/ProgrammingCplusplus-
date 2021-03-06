/*Exercise 3.26: In the binary search program on page 112, why did we write 
mid = beg + (end - beg) / 2; instead of mid = (beg + end) /2;  ? */ 

/* Answer : the only thing I can think of is that by using (beg+end)/2 we temporarily go to memory places 
beg+end that are beyond the scope of the vector and possibly beyond the machines memory, before we divide by 2!
I suppose that is dangerous.   */

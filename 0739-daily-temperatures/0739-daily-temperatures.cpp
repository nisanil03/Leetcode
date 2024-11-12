class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
       deque<int> deque;

       vector<int> res (temp.size(),0);

       for(int i = temp.size() - 1; i >= 0; --i)
       {
           if(deque.empty())
           {
               deque.push_front(i);
               res[i] = 0;
           }
           else{
               while(!deque.empty() && temp[i] >= temp[deque.front()])
               {
                   deque.pop_front();
               }
               if(deque.empty())
               {
                   res[i] = 0;
               }
               else
               {
                   res[i] = deque.front() - i;
               }
               deque.push_front(i);
           }
       } 
       return res;
    }
};
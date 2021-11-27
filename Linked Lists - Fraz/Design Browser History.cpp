class BrowserHistory {
public:
    list<string> history;
    list<string> :: iterator it;
    
    // Starting point - New tab of our browser
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        // A dummy iterator used to delete all nodes after 'it'
        // eg : If I visited youtube->gmail->facebook then came back to youtube and from there went to leetcode so I will have to delete gmail->facebook connection and 
        // connect youtube->leetcode
        auto del = it;
        del++;
        history.erase(del, history.end());
        
        // Now insert the new url i.e leetcode from our example and make 'it' point to it
        history.push_back(url);
        it++;
    }
    
    // Implement the back button 
    string back(int steps) {
        // it != history.begin() -> Suppose if we just browsed 2 pages and then try to go back 10 pages, it is not possible. So check for that.
        while(it != history.begin() && steps--){
            it--;
        }
        
        // We have to return the url in string so dereference it
        return *it;
    }
    
    string forward(int steps) {
        // As history.end() points to place after last node we have to predecrement it
        while(it != (--history.end()) && steps--){
            it++;
        }
        
        return *it;
    }
};

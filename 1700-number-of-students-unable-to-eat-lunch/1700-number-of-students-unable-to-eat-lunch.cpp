class Solution {
public:
int countStudents(vector<int>& students, vector<int>& sandwiches) {
     stack<int> st;
     for(int i=sandwiches.size()-1; i>=0; i--) st.push(sandwiches[i]);
     
    int student_1  = 0;
    int student_0 = 0;
    for(auto it=0; it<students.size(); it++) {
        if(students[it] == 0) student_0++;
        else student_1++;
    }
    
    while(!st.empty()){
        if( st.top() == 1 && 0 < student_1 ) {
            st.pop();
            student_1--;
        }
        else if(st.top() == 0 && 0 < student_0) {
            st.pop();
            student_0--;
        }
        else break;
    }
    return st.size();
}

};
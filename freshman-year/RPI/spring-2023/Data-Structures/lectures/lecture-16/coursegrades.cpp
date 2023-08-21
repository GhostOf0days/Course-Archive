//typedef std::map<Name,StudentRecord>::iterator StuItr
typedef std::map<Name,StudentRecord> StuMap
typedef StuMap::iterator  StuItr;


std::map<Name,StudentRecord> students;
Name X; //has some name we want
std::string Y; //has the name of a course we want

//This was for finding a particular student/grade
StuItr m_it;
m_it = students.find(X); //O(log s)
if(m_it != students.end()){ //We found the student
  if(m_it->second.hasCompletedCourse(Y)){  //O(k)
    //Find the course grade
    string grade = m_it->second.getCourseGrade(Y); //O(k)
  }
}

// O(log s + k + k) -> O(log s + k)


string StudentRecord::getCourseGrade(const string &course_name) const{
  for(unsigned int i=0; i<completed_coursework.size(); i++){
    if(completed_coursework[i].get_course_name() == course_name){
      return completed_coursework[i].get_final_grade();
    }
  }
}

bool StudentRecord::hasCompletedCourse(const string &course_name) const{
  for(unsigned int i=0; i<completed_coursework.size(); i++){
    if(complete_coursework[i].get_course_name() == course_name){
      return true;
    }
  }
  return false;
}










//Answer to above question: use .getGradeInCourse()
//This is finding all students in a particular course
std::list<Name> students_in_course;
std::map<Name,StudentRecord> students;
std::string Y; //has the name of a course we want

//Average map::iterator++  O(1)
//Worst case map::iterator++ for all s entries, O(s)
//O(s)
for(StuItr m_it = students.begin(); m_it!=students.end(); m_it++){
	if(m_it->second.hasCompletedCourse(Y){    //O(k)
		//Do something
		students_in_course.push_back(m_it->first);   //O(1) push back
		//students_in_course.push_back((*m_it).first);
	}
}

//O(s*k)
//We do p pushbacks  --> O(p)

//O(s*k + p) BUT.....  p pushbacks <= s
//O(s*k + s) worst case, p == s
//O(s*(k+1))
//==> //O(s*k)
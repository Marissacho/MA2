#include <map>
#include "generateUsers.hpp"
using namespace std;
map<string, User> buildMapByUserName(vector<User> users) {
map<string, User> usersMap;
for (const auto& user:users){
userMap[user.userName]=user;
}
return usersMap;
}
map<string, User> buildMapByEmail(vector<User> users) {
map<string, User> emailMap;
for (const auto& user:users){
emailMap[user.userName]=user;
}
return emailMap;
}
void printMap(map<string, User> aMap) {
cout << "Username: " <<key<<", User Details: "<<user<< endl;
}
bool isMapSorted(map<string, User> aMap) {
if ( aMap.empty() ){
return true;
}
auto i=aMap.begin();
auto prev= i++;
while(i!=aMap.end()){
if(prev->first >i->first){
return false;
}
prev=i++;
}
return true;
}
bool testSearchByKey(map<string, User> aMap, string keyToSearch) {
return userMap.find(key)!=userMap.end();
}
bool testDeleteByKey(map<string, User> aMap, string keyToDelete) {
return userMap.erase(key)>0;
}
void printActiveUsers(map<string, User> aMap) {
int a = 900;
for(const auto&[userName, user]:aMap){
if(user.i>a){
cout<<"Active User:"<<user.userName<<"with"<<user.i<<"updates"<<endl;
}
}
}
void printMostPopularCategory(map<string, User> aMap) {
std::map<std::string, int> categoryCount;
for(const auto&[userName,user]:aMap){
categoryCount[user.mostPopularCategory]++;
}
string mostPopularCategory;
int maxCount=0;
for(const auto&[category, count]: categoryCount){
if(count>maxCount){
maxCount= count;
mostPopularCategory=category;
}
}
cout<<"Most popular category:"<<mostPopularCategory<<endl;
}
int main()
{
int numUsers = 10;
vector<User> users = generateUsers(numUsers);
cout << "Build map with username as key" << endl;
map<string, User> mapByUserName = buildMapByUserName(users);
if ( mapByUserName.size() == numUsers )
cout << " Built successfully." << endl << endl;
else
cout << " Built unsuccessfully." << endl << endl;
cout << "Print \"mapByUserName\" map:" << endl;
printMap(mapByUserName);
cout << endl;
string keyToSearch = "smith55";
cout << "Search by key: mapByUserName[\"" << keyToSearch << "\"]" << endl;
if ( testSearchByKey(mapByUserName, keyToSearch) )
cout << " Search successfully." << endl << endl;
else
cout << " Search unsuccessfully." << endl << endl;
string keyToDelete = "smith55";
cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
if ( testDeleteByKey(mapByUserName, keyToDelete) )
cout << " Delete successfully." << endl << endl;
else
cout << " Delete unsuccessfully." << endl << endl;
cout << "Test if map's key is sorted" << endl;
if ( isMapSorted(mapByUserName) )
cout << " Order test passed!" << endl << endl;
else
cout << " Order test failed!" << endl << endl;
cout << "Print usernames with more than 800 tweets:" << endl;
printActiveUsers(mapByUserName);
cout << endl;
cout << "Print the most popular category" << endl;
printMostPopularCategory(mapByUserName);
cout << endl;
cout << "
============================================================================== " <<
endl << endl;
cout << "Build map with username as key" << endl;
map<string, User> mapByEmail = buildMapByEmail(users);
if ( mapByEmail.size() == numUsers )
cout << " Built successfully." << endl << endl;
else
cout << " Built unsuccessfully." << endl << endl;
keyToSearch = "kat@gmail.com";
cout << "Search by key: mapByEmail[\"" << keyToSearch << "\"]" << endl;
if ( testSearchByKey(mapByEmail, keyToSearch) )
cout << " Search successfully." << endl << endl;
else
cout << " Search unsuccessfully." << endl << endl;
keyToDelete = "kat@gmail.com";
cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
if ( testDeleteByKey(mapByEmail, keyToDelete) )
cout << " Delete successfully." << endl << endl;
else
cout << " Delete unsuccessfully." << endl << endl;
return 0;
}


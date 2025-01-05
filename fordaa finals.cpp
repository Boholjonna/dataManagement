#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // For setw()
#include <algorithm>  // For transform
#include <cctype>     // For tolower

using namespace std;

struct Books{
	
	/*we used struct (a user-defined data structure that groups together different types of data)
	 as the container for the related variales listed below*/
	
	//vectors for the variables defined to store the multiple book variable entries
		vector<string> title;
		vector<string> author;
		vector<int> isbn;
		
	
    // Function to display the data list in a formatted table (dataList function)
    void dataList() {
        cout << endl << endl;
         cout << "--------------------------------------------------------------------------------------------------------" << endl ;
        // Print the header row with fixed width for each column (setw() ensures that each column has a fixed width.
        cout << left << setw(5) << "No." 
             << setw(40) << "T I T L E"   // Fixed width for title column
             << setw(30) << "A U T H O R" // Fixed width for author column
             << setw(15) << "I S B N"     // Fixed width for ISBN column
             << endl;
        
        cout << "--------------------------------------------------------------------------------------------------------" << endl;

        // Print the data rows with fixed column widths
        for (size_t i = 0; i < title.size(); i++) { //this loop runs through all books and prints their details in the table
            cout << left << setw(5) << i + 1   // No. column (i+1 used to print row numbers starting from 1)
                 << setw(40) << title[i]      // Title column with fixed width
                 << setw(30) << author[i]     // Author column with fixed width
                 << setw(15) << isbn[i]       // ISBN column with fixed width
                 << endl;
        }
        
        cout << endl << "--------------------------------------------------------------------------------------------------------" << endl ;
    }
	

	
	
	  // Function to input book data (inputData Function) - prompts user to enter book details
    void inputData(int n) {
        string titleInput, authorInput;
        int isbnInput;

        for (int i = 1; i <= n; i++) {
            cout << "\nInput Title " << i << ": ";
            cin.ignore();  // To ignore any extra newline character
            getline(cin, titleInput);  // Using getline to allow spaces in title (allows multi-word input)

            cout << "Input Author " << i << ": ";
            getline(cin, authorInput);  // Using getline for the author name as well

            cout << "Input ISBN " << i << ": ";
            cin >> isbnInput;  // ISBN is an integer, so we use cin

            // Store data in the vectors
            title.push_back(titleInput);
            author.push_back(authorInput);
            isbn.push_back(isbnInput);
            //push.back() is used to store the inputs within the defined vectors
        }
    }
    
    
	
    bool hasData() { //function returns true when the vectors are not empty, meaning there are existing book entries
    return !title.empty() && !author.empty() && !isbn.empty();
}

    	
   	void option( ){	  
    // Check if there is existing data, if there is existing data - it gives the user options: Search, Add, or Delete
    if (hasData()) {
    	
    	int n;
    	
        cout << endl << endl << " There are existing books, what would you like to do with it ? " << endl << endl;
         cout<<  " 1. Search" << endl ;
          cout<<  " 2. Add " << endl ;
           cout<<  " 3. Delete " << endl << endl  ;
           
           cout << "Please enter desired number: " ;
           cin>> n;
           

		   
		   if (n==1){ //option 1: search - user will be able to search through the existing list
           			dataList();
           				search();
           			option();
           			
           	
		   }
		   
		   if (n==2){ //option 2: add - user will add books to the list
		   			int books;
		   			cout << endl << endl << "Please enter the number of books you would like to add: " ;
		   			cin>>books;
				   	inputData(books);
           			dataList();
           			cout << endl << endl << "Data added...." ;
           			option();
           	
		   }
           
           if (n==3){ //option 3: delete - user will be able to delete an entry 
           				int num ;
           				dataList();
           				 cout << "Please enter coulumn number : " ;
        				   cin>> num;
           			deleteData(num); 
           			option();
           			
           	
		   }
		   
		   else{
		   	cout << endl << endl << "Invalid Input...  " ;
		   	option();
		   }
		   
           
           
           
        // You can add more options here like viewing or deleting data
    } 
	else  { //if hasdata() function returns false, it will ask the user to input book entries
       
        // Option to input data could be added here
        int n;
		    cout << " Data is empty, please input data....... " << endl  << endl ;
		    cout << " How many books would you like to input? : " ;
		    cin>> n;
        
        
          inputData(n);
          dataList();
          option();
          
    }
}



// Function to delete an entry by index
void deleteData(int index) {
    // Check if index is valid
    if (index < 1 || index > title.size()) {
        cout << "Invalid index! Please enter a valid number." << endl;
        return;
    }

    // Adjust index to match zero-based indexing of vectors
    index--;

    // Erase the elements from all vectors
    title.erase(title.begin() + index);
    author.erase(author.begin() + index);
    isbn.erase(isbn.begin() + index);

    cout << endl <<  "Data at column " << index + 1 << " deleted successfully!" << endl;
    dataList();
}


string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

 // Function to search for a book
    void search() {
        bool found = false;
        int n;
        cout << endl << endl << "What would you like to search for? ";
        cout << endl << "1. Title " << endl << "2. Author" << endl << "3. ISBN"; 
        cout << endl << "Enter your choice: "; 
        cin >> n;

        // Searching by Title
        if (n == 1) {
            string inputTitle;
            cout << endl << "Please input the title: "; 
            cin.ignore();  // Ignore whitespace
            getline(cin, inputTitle);  // Use getline to allow spaces in title
            inputTitle = toLowerCase(inputTitle);  // Convert to lowercase for comparison

            // Compare input title with each title in the vector
            for (size_t i = 0; i < title.size(); i++) {
                if (toLowerCase(title[i]) == inputTitle) {
                    found = true;  cout << "Found  at column " << i+1 << endl;
                 
                }
            }

            if (!found) {
                cout << "Title not found." << endl;
                
            }
        }
        // Searching by Author
        else if (n == 2) {
            string inputAuthor;
            cout << endl << "Please input the author: ";
            cin.ignore();  // Ignore whitespace
            getline(cin, inputAuthor);  // Use getline to allow spaces in author name
            inputAuthor = toLowerCase(inputAuthor);  // Convert to lowercase for comparison

            // Compare input author with each author in the vector
            for (size_t i = 0; i < author.size(); i++) {
                if (toLowerCase(author[i]) == inputAuthor) {
                    found = true;
                       cout << "Found  at column " << i+1 << endl;
                    
                }
            }

            if (!found) {
                cout << "Author not found." << endl;
            }
        }
        // Searching by ISBN
        else if (n == 3) {
            int inputIsbn;
            cout << endl << "Please input the ISBN: ";
            cin >> inputIsbn;

            // Compare input ISBN with each ISBN in the vector
            for (size_t i = 0; i < isbn.size(); i++) {
                if (isbn[i] == inputIsbn) {
                    found = true;
                   cout << "Found  at column " << i+1 << endl;
                   
                }
            }

            if (!found) {
                cout << "ISBN not found." << endl;
            }
        }
        
        else{
        	cout << endl <<  "Invalid Input " ;
		}
        

        if (found) {
            dataList();  // Display the updated data list
        }
    }



	
	};



int main() { //Displays the ASCII art for Book Data Management, initializes a book object, and calls the menu system
	
    int n ;
    
    
    cout << R"(______  _____  _____ _   __ ______  ___ _____ ___   ___  ___  ___   _   _   ___  _____  ________  ___ _____ _   _ _____ 
| ___ \|  _  ||  _  | | / / |  _  \/ _ \_   _/ _ \  |  \/  | / _ \ | \ | | / _ \|  __ \|  ___|  \/  ||  ___| \ | |_   _|
| |_/ /| | | || | | | |/ /  | | | / /_\ \| |/ /_\ \ | .  . |/ /_\ \|  \| |/ /_\ \ |  \/| |__ | .  . || |__ |  \| | | |  
| ___ \| | | || | | |    \  | | | |  _  || ||  _  | | |\/| ||  _  || . ` ||  _  | | __ |  __|| |\/| ||  __|| . ` | | |  
| |_/ /\ \_/ /\ \_/ / |\  \ | |/ /| | | || || | | | | |  | || | | || |\  || | | | |_\ \| |___| |  | || |___| |\  | | |  
\____/  \___/  \___/\_| \_/ |___/ \_| |_/\_/\_| |_/ \_|  |_/\_| |_/\_| \_/\_| |_/\____/\____/\_|  |_/\____/\_| \_/ \_/  
                                                                                                                        
                                                                                                                        )" << '\n'  << endl << endl << endl ;  

    
     Books book; 

    book.option();
    

    
    
    return 0;
}
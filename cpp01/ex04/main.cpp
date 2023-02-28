#include <iostream>
#include <fstream>

//this function will replace the string with the replacement string in the inputline 
//and return the changed outputline
static std::string replacing(   const std::string& inputline, 
                                const std::string& toBeReplaced,
                                const std::string& replacement){
    
    //setup the variables
    size_t  sizeInput = inputline.size();
    size_t  sizeToBeReplaced = toBeReplaced.size();
    std::string outputline = "";
    size_t pos = 0;
    size_t pos2 = 0;

    while (pos2 != std::string::npos){   
        //get the potential position of word to be replaced
	    pos2 = inputline.find_first_of(toBeReplaced[0], pos);
		if (pos2 == std::string::npos) //if not found append the rest of the string
        	outputline.append(inputline.substr(pos,sizeInput - pos));
		else{
            //append till the potential position
			outputline.append(inputline.substr(pos, pos2-pos));
            //check if the potential equals the word to be replaced
			if(toBeReplaced.compare(inputline.substr(pos2,sizeToBeReplaced)) == 0){
                //if it is append the replacement and update pos
				outputline.append(replacement);
				pos = pos2 + sizeToBeReplaced;
			}
			else{
                //else append the first character of to be replaced and update pos
				outputline.append(1, toBeReplaced[0]);
				pos = pos2 + 1;
			}
		}
    }
	return (outputline);
}

int main(int argc, char *argv[]){

    if(argc != 4){
        std::cout << "USAGE: ./sedLoser <filename> <to be replaced> <replacement>\n";
        return (0);
    }
    
    std::string inputfile = argv[1];
    std::string outputfile = inputfile + ".replace";
    std::string toBeReplaced = argv[2];
    std::string replacement = argv[3];

    if(toBeReplaced.size() == 0){
        std::cout << "The word to be replaced can't be empty." << std::endl;
        return (0);
    }

    std::ifstream istream(inputfile.c_str());
    if(!istream.is_open()){
        std::cout << inputfile + " can't be opened" << std::endl;
        return (1);
    }

    std::ofstream ostream(outputfile.c_str());
    if(!ostream.is_open()){
        std::cout << outputfile + " can't be created"  << std::endl;
        istream.close();
        return (1);
    }    

    while(!istream.eof()){
        std::string input;
        getline(istream,input);
        std::string output = replacing(input, toBeReplaced, replacement);
        if(!istream.eof())
            ostream << output << std::endl;  
    }

    istream.close();
    ostream.close();
    return (0);
}
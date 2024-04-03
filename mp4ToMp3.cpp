// Requeriments: Had ffmpeg already installed.
//Made by boowithbuds
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string input_file, output_file;

    std::cout << "Enter the path of the input MP4 file: ";
    std::getline(std::cin, input_file);

    // Generate output file name in the same directory as input file
    size_t last_slash = input_file.find_last_of("/\\");
    std::string path = input_file.substr(0, last_slash + 1);
    std::string input_filename = input_file.substr(last_slash + 1);
    size_t extension_pos = input_filename.find_last_of(".");
    output_file = path + input_filename.substr(0, extension_pos) + ".mp3";

    std::string command = "ffmpeg -i \"" + input_file + "\" -vn -acodec libmp3lame -ab 128k \"" + output_file + "\"";

    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Successful conversion. The MP3 file has been saved as: " << output_file << std::endl;
    } else {
        std::cerr << "Error during conversion." << std::endl;
        return 1;
    }

    system("pause");
    return 0;
}
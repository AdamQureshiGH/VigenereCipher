    #include <iostream>
    #include "Vigenere.h"
    #include "../cpp-httplib/httplib.h"

    void handleEncryptRequest(const httplib::Request& req, httplib::Response& res) {
        Vigenere vigenere;

        std::string plaintext = req.get_param_value("plaintext");
        std::string key = req.get_param_value("key");

        // Call the encryption function
        std::string ciphertext = vigenere.Encrypt(plaintext, key);

        // Send the ciphertext back to the client
        res.set_content(ciphertext, "text/plain");
    }
    void handleDecryptRequest(const httplib::Request& req, httplib::Response& res) {
        Vigenere vigenere;

        std::string ciphertext = req.get_param_value("ciphertext");
        std::string key = req.get_param_value("key");

        // Call the decryption function
        std::string plaintext = vigenere.Decrypt(ciphertext, key);

        // Send the plaintext back to the client
        res.set_content(plaintext, "text/plain");
    }
    void serveHTML(const httplib::Request& req, httplib::Response& res) {
    std::ifstream htmlFile("public/index.html");
    if (htmlFile.is_open()) {
        std::string htmlContent((std::istreambuf_iterator<char>(htmlFile)),
                                std::istreambuf_iterator<char>());
        res.set_content(htmlContent, "text/html");
    } else {
        res.status = 404;
        res.set_content("404 Not Found", "text/plain");
    }
    }   
    int main()
    {

        std::string plainText;
        std::string newText;
        bool IsEncrypted;
        //Get the User Input
        //Make sure the input is valid
        //Ask if the text is already encrypted or not

        //use these stats to plug into the encrypt or decrypt function and return it to the newText 
        //Use Output handeler to display text

        httplib::Server svr;
        // Route for encryption requests
        //It tells the server: "If someone sends a POST request to /encrypt, I want you to call the handleEncryptRequest function."
        svr.Get("/", serveHTML);

        svr.Post("/encrypt", handleEncryptRequest);

        // Route for decryption requests
        svr.Post("/decrypt", handleDecryptRequest);

        std::cout << "Server running at http://localhost:8080" << std::endl;
        svr.listen("localhost", 8080);  // Start the server
    
    }    
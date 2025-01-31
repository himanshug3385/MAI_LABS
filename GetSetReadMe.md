<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
</head>

<body>

  <h1>GetSetService</h1>
  <p>This project provides a simple user management service that allows adding users, retrieving users by ID, and listing all users. It includes basic authentication to secure operations.</p>

  <h2>Features</h2>
  <ul>
        <li><strong>Set User:</strong> Adds a new user with a unique ID and name.</li>
        <li><strong>Get User by ID:</strong> Retrieves a user based on the provided ID.</li>
        <li><strong>List All Users:</strong> Lists all the users stored in the service.</li>
        <li><strong>Authentication:</strong> The operations are protected by simple authentication (username: "admin", password: "password").</li>
    </ul>

  <h2>Classes and Functions</h2>
  <h3>User Class</h3>
  <p>The <code>User</code> class represents a user with the following attributes:</p>
   <ul>
        <li><code>id</code>: Unique identifier for the user.</li>
        <li><code>name</code>: Name of the user (must be at least 2 characters long).</li>
    </ul>

   <h3>GetSetService Class</h3>
  <p>The <code>GetSetService</code> class provides the following functionality:</p>
  <ul>
        <li><code>authenticate(username, password)</code>: Verifies if the provided credentials match the valid ones.</li>
        <li><code>setUser(id, name, username, password)</code>: Adds a new user if authentication is successful.</li>
        <li><code>getUserById(id, username, password)</code>: Retrieves a user by their ID after authentication.</li>
        <li><code>listAllUsers(username, password)</code>: Lists all users after authentication.</li>
    </ul>

  <h2>How It Works</h2>
    <p>The program allows users to be added to the system with unique IDs and names. All actions (setting, getting, and listing users) require authentication, which is performed by checking the provided username and password against hardcoded credentials ("admin" and "password").</p>


  <h2>Requirements</h2>
    <ul>
        <li>C++11 or later</li>
        <li>A C++ compiler that supports the <code>map</code> container and <code>exception</code> handling.</li>
    </ul>

    

</body>

</html>

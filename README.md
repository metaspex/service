Warning: you need the Metaspex product to compile this application. Please contact us at info@metaspex.com to get access to Metaspex.

This sample Metaspex application leverages the service construct.

A service (c.f. the reference guide) allows a server to respond to client HTTP JSON requests.

Apply the instructions below in the debug or opt directory of one of the Web servers.

To compile:

make

Go down (cd) into the Web server of your choice (apache or nginx) and the variant (debug or opt).

To load (or reload) the module in the Web server:

make server

To test that the module was properly installed (use port 8080 for the default Apache configuration and 8081 for Nginx):

curl http://localhost:8081/_

It should display the "Ave" message, which is something like:

{"hx2a":"Ave","Nginx version":"1.20.2","hx2a version":"2.0.3","hx2a build date":"Mar 14 2022 09:01:41"}

To test the "echo" service (same remark on port number):

curl http://localhost:8081/echo -d '{"message": "Hello"}'

It should display something like:

{"ok":1,"msg":"Hello from 127.0.0.1"}

You can change the string "Hello" and see what happens.

In case of failure, the log files are configured to be written locally. Have a look at them when something fails.
The configuration file has a commented-out option to initiate tracing, which is slowing down the application, but
provides even more information.

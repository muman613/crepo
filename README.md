# README

## Overview
*crepo* is a repository maintenance tool which allows several git repositories to be managed with a single command. Similar to *repo* the new *crepo* loads a manifest XML file which determines which git repositories to pull down.

## Features
*crepo* provides the following features:

- Clone/Check-Out/Diff/Status commands supported.
- Maintains multiple git repositories using XML control file.
- Compiles on Linux and Cygwin Windows.
- Uses the *build* scripts to build tool.

## Building project

1. Create directory to build project in.
	* `mkdir muman-github`
	* `cd muman-github`
2. Check out the *build* repository.
	* `git clone git@github.com:muman613/build.git`
3. Check out the *crepo* repository.
	* `git clone git@github.com:muman613/crepo.git`
4. Change into the *crepo* directory and `make`.
	* `cd crepo`
	* `make`

#### TODO
- Add support for check-in
- Make multi-threaded  to support parallel check-out.

####XML example
~~~xml
<body>
	<tag>Data</tag>
</body>
~~~

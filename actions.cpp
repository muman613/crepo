#include "StdAfx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <iostream>
#include <popt.h>
#include "functions.h"
#include "utils.h"
#include "repoObject.h"
#include "actions.h"

/**
 *
 **/


bool diff_handler(const crepo_parms& parms) {
    bool bRes = false;
    STRING sDirectory = ".crepo";
    STRING sFile = sDirectory + "/default.xml";

    if (file_or_dir_exists(sFile, FILE_FLAG)) {
        repoObject  repo;
        //printf("found the crepo!\n");

        if (repo.LoadRepoFromXML( sFile )) {
            //printf("Repo loaded!\n");
            repo.DiffRepo();
            bRes = true;
        }
    } else {
        printf("Must run crepo at root of crepo repository!\n");
    }

    return bRes;
}

/**
 *
 **/

bool checkout_handler(const crepo_parms& parms) {
    bool bRes = true;
    STRING sDirectory = ".crepo";
    STRING sFile;

    if (!parms.sCheckoutDir.empty()) {
        if (!file_or_dir_exists(parms.sCheckoutDir, FILE_FLAG|DIR_FLAG)) {
            make_directory( parms.sCheckoutDir );
        }

        sDirectory = parms.sCheckoutDir + "/.crepo";
    }

    if (!file_or_dir_exists(sDirectory, DIR_FLAG)) {
        if (git_checkout(parms.sRepoURL, "", sDirectory) == 0) {
            STRING sFile = sDirectory + "/default.xml";

            if (file_or_dir_exists(sFile, FILE_FLAG)) {
                repoObject repoObj(parms.sCheckoutDir);

                //printf("found default.xml!\n");

                if (repoObj.LoadRepoFromXML(sFile)) {
                    if (repoObj.CheckoutRepo()) {
                        printf("OK\n");
                    } else {
                        printf("FAILED\n");
                    }
                }
            } else {
                fprintf(stderr, "ERROR: Unable to find manifest!\n");
                bRes = false;
            }
        } else {
            fprintf(stderr, "ERROR: Unable to checkout manifest!\n");
            bRes = false;
        }
    } else {
        fprintf(stderr, "ERROR: .crepo already exists!\n");
        bRes = false;
    }

    return bRes;
}

/**
 *
 **/

bool stat_handler(const crepo_parms& parms) {
    bool bRes = false;
    STRING sDirectory = ".crepo";
    STRING sFile = sDirectory + "/default.xml";

    if (file_or_dir_exists(sFile, FILE_FLAG)) {
        repoObject  repo;

        if (repo.LoadRepoFromXML( sFile )) {
            repo.StatRepo();
            bRes = true;
        }
    } else {
        printf("Must run crepo at root of crepo repository!\n");
    }

    return bRes;
}

/**
 *
 **/

bool branch_handler(const crepo_parms& parms) {
    bool bRes = false;
    STRING sDirectory = ".crepo";
    STRING sFile = sDirectory + "/default.xml";

    if (file_or_dir_exists(sFile, FILE_FLAG)) {
        repoObject  repo;

        if (repo.LoadRepoFromXML( sFile )) {
            repo.BranchRepo();
            bRes = true;
        }
    } else {
        printf("Must run crepo at root of crepo repository!\n");
    }

    return bRes;
}

/**
 *
 **/

bool help_handler(const crepo_parms&) {
    printf("crepo [action] [options]\n");
    printf("\n");
    printf("Actions:\n");
    printf("  help    - print this help text\n");
    printf("  version - print the version number\n");
    printf("  co      - check out repository\n");
    printf("  diff    - perform diff on all repositories\n");
    printf("  stat    - display status on all repositories\n");
    printf("\n");

    return true;
}

/**
 *
 **/

bool version_handler(const crepo_parms&) {
    printf("%s version %d.%d [%s]\n", szAppName,
           CREPO_MAJOR_VERSION, CREPO_MINOR_VERSION, szBuildDate);

    return true;
}

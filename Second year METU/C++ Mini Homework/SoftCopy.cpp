#include "SoftCopy.h"
/* YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. DO NOT MODIFY THE HEADER FILE AS IT WILL BE
REPLACED BY THE ORIGINAL HEADER DURING TESTING. THE REQUIRED
HEADER FILE IS ALREADY INCLUDED FOR YOU ABOVE THIS COMMENT BLOCK.
THE CONSTRUCTOR and DESTRUCTOR ARE ALREADY IMPLEMENTED.
START YOUR IMPLEMENTATIONS BELOW THOSE. */


// DONE
SoftCopy::SoftCopy(int ISBN, double price, int startPage, int endPage) : Book(ISBN, price) {
	this->startPage = startPage;
	this->endPage = endPage;
	this->numberOfPages = (endPage - startPage) + 1;
	this->firstHalf = NULL;
	this->secondHalf = NULL;
	this->pageContent = "";
}

SoftCopy :: SoftCopy(const SoftCopy& rhs) {
	this->price = rhs.price;
	this->ISBN = rhs.ISBN;
    this->startPage = rhs.startPage;
	this->endPage = rhs.endPage;
	this->numberOfPages = (endPage - startPage) + 1;
	this->next = rhs.next;
	if (rhs.firstHalf) {
	    this->firstHalf = new SoftCopy(*rhs.firstHalf);
	}
	else {
	    firstHalf = NULL;
	}
	if (rhs.secondHalf) {
	    this->secondHalf = new SoftCopy(*rhs.secondHalf);
	}
	else {
	    secondHalf = NULL;
	}
	this->pageContent = rhs.pageContent;
}

SoftCopy& SoftCopy :: operator=(const SoftCopy& rhs) {
    
	this->price = rhs.price;
	this->ISBN = rhs.ISBN;
    this->startPage = rhs.startPage;
	this->endPage = rhs.endPage;
	this->numberOfPages = (endPage - startPage) + 1;
	this->next = rhs.next;
	if (this->firstHalf) {
	    delete this->firstHalf;
	}
	if (rhs.firstHalf) {
	    this->firstHalf = new SoftCopy(*rhs.firstHalf);
	}
	else {
	    this->firstHalf = NULL;
	}
	if (this->secondHalf) {
	    delete this->secondHalf;
	}
	if (rhs.secondHalf) {
	    this->secondHalf = new SoftCopy(*rhs.secondHalf);
	}
	else {
	    this->secondHalf = NULL;
	}
	this->pageContent = rhs.pageContent;
	return *this;
}

SoftCopy& SoftCopy :: operator+(const SoftCopy& rhs) const {
	SoftCopy* newSoftCopy = new SoftCopy(*this);
	SoftCopy* temp = NULL;
    if (rhs.startPage == rhs.endPage) {
		newSoftCopy->UploadPage(rhs.pageContent, rhs.startPage);
	}
	if (rhs.secondHalf) {
		SoftCopy* temp = &(*newSoftCopy + *rhs.secondHalf);
		delete newSoftCopy;
		newSoftCopy = temp;
	}
	if (rhs.firstHalf) {
		SoftCopy* temp = &(*newSoftCopy + *rhs.firstHalf);
		delete newSoftCopy;
		newSoftCopy = temp;
	}
	return *newSoftCopy;
}

Book* SoftCopy :: Clone() const {
    return new SoftCopy(*this);
}

void SoftCopy :: Discount() {
    this->price = this->price * 0.75;
}

void SoftCopy::UploadPage(string content, int page) {
	if (numberOfPages == 2 && startPage == page && !(firstHalf)){
        firstHalf = new SoftCopy(ISBN, price, page, page);
        firstHalf->next = NULL;
  	    firstHalf->pageContent = content;
    }
    else if (numberOfPages == 2 && startPage == page) {
        delete firstHalf;
        firstHalf = new SoftCopy(ISBN, price, page, page);
        firstHalf->next = NULL;
        firstHalf->pageContent = content;
    }
    else if (numberOfPages == 2 && endPage == page && !(secondHalf)){
        secondHalf = new SoftCopy(ISBN, price, page, page);
        secondHalf->next = NULL;
        secondHalf->pageContent = content;
    }
    else if (numberOfPages == 2 && endPage == page) {
        delete secondHalf;
        secondHalf = new SoftCopy(ISBN, price, page, page);
        secondHalf->next = NULL;
        secondHalf->pageContent = content;
    }
    else if (numberOfPages == 3 && page == endPage && !(secondHalf)) {
        secondHalf = new SoftCopy(ISBN, price, page, page);
        secondHalf->next = NULL;
        secondHalf->pageContent = content;
    }
    else if (numberOfPages == 3 && page == endPage) {
        delete secondHalf;
        secondHalf = new SoftCopy(ISBN, price, page, page);
        secondHalf->next = NULL;
        secondHalf->pageContent = content;
    }
	else if (numberOfPages == 3 && firstHalf) {
        firstHalf->UploadPage(content,page);
    }
	else if (numberOfPages == 3 && !(firstHalf)) {
        firstHalf = new SoftCopy(ISBN, price, startPage, startPage + 1);
        firstHalf->next = NULL;
        firstHalf->UploadPage(content,page);
    }
	else if (page < endPage - numberOfPages/2 + 1 && firstHalf) {
        firstHalf->UploadPage(content,page);
	}
	else if (page < endPage - numberOfPages/2 + 1  && !(firstHalf)) {
        firstHalf = new SoftCopy(ISBN, price, startPage, startPage + numberOfPages/2 - 1/2);
        firstHalf->next = NULL;
        firstHalf->UploadPage(content,page);
	}
	else if (secondHalf) {
        secondHalf->UploadPage(content,page);
	}
	else if (!(secondHalf)) {
        secondHalf = new SoftCopy(ISBN, price, endPage - numberOfPages/2 + 1, endPage);
        secondHalf->next = NULL;
        secondHalf->UploadPage(content,page);
    }
	return;
}

string SoftCopy :: Display(int from, int to) const {
    string strOut;
    if (startPage == endPage && startPage >= from && endPage <= to) {
		strOut = pageContent;
	}
	else if (startPage != endPage){
		if (firstHalf && !(secondHalf)) {
		    if (firstHalf->Display(from, to) != "") {
			    strOut = firstHalf->Display(from, to);
		    }
		}
		else if (!(firstHalf) && secondHalf) {
		    if (secondHalf->Display(from, to) != "") {
			    strOut = secondHalf->Display(from, to);
		    }
		}
		else if (firstHalf && secondHalf){
		    if (firstHalf->Display(from, to) != "" && secondHalf->Display(from, to) != "") {
			    strOut = firstHalf->Display(from, to) + "\n" + secondHalf->Display(from, to);
		    }
		    else if (firstHalf->Display(from, to) == "" && secondHalf->Display(from, to) != "") {
		        strOut = secondHalf->Display(from, to);
		    }
		    else if (firstHalf->Display(from, to) != "" && secondHalf->Display(from, to) == "") {
		        strOut = firstHalf->Display(from, to);
		    }
		    else {
		        strOut = "";
		    }
		}
	}
    return strOut;
}

// DONE
SoftCopy::~SoftCopy() {
	if (firstHalf != NULL)
		delete firstHalf;
	if (secondHalf != NULL)
		delete secondHalf;
}






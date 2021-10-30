// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
        //         using raw pointers
        for (auto i = 0u; i < desc.size(); i++){
            for (auto j = 0u; j < price.size(); j++){
                if (price[j].code == desc[i].code ){
                    Product *n_pr = new Product(desc[i].desc, price[j].price);
                    n_pr->validate();
                    priceList += n_pr;
                    delete n_pr;
                    n_pr = nullptr;
                }
            }
        }
		return priceList;
	}
    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price){
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
        //         using smart pointers
        for (auto i = 0u; i < desc.size(); i++) {
            for (auto j = 0u; j < price.size(); j++){
                if (desc[i].code == price[j].code) {
                    unique_ptr<Product> pr(new Product(desc[i].desc, price[j].price));
                    pr->validate();
                    priceList += std::move(pr);
                }
            }
        }
		return priceList;
	}

}

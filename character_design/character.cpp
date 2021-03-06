#include "character.h"
#include <QtAlgorithms>
character::character(QObject *parent,QLabel* label) : QObject(parent),show(label)
{
}


void character::addfeature( feature* new_feature)
{
    property.append(new_feature);
}

void character::setComboBox(QComboBox* box)
{
    for(int i=0;i<size();i++)
        box->addItem(property[i]->getName());
}

void character::setLabel(const QString & name)
{
//    for(int i=0;i<size();i++)
//    {
//        if (property[i]->getName()==name)
//        {

//            show->setPixmap(property[i]->getImage());
//        }
//    }
    auto position=std::find_if(property.begin(),property.end()
                 ,[=](feature* input){return (name==input->getName());});
    show->setPixmap((*position)->getImage());

}

int character::size() const
{
    return property.size();
}

QString character::get_name(int pos) const
{
    return property[pos]->getName();
}






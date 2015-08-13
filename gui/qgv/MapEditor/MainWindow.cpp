/***************************************************************
QGVCore Sample
Copyright (c) 2014, Bergont Nicolas, All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
***************************************************************/
#include "MainWindow.h"
#include "moc_MainWindow.cpp"
#include "ui_MainWindow.h"
#include "QGVScene.h"
#include "QGVNode.h"
#include "QGVEdge.h"
#include "QGVSubGraph.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_map(nullptr),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _scene = new QGVScene("DEMO", this);
    ui->graphicsView->setScene(_scene);


    m_map = new risk::map::map("Earth");

    auto south_america = m_map->add_continent("South America");
    auto brazil = m_map->add_territory(south_america, "Brazil");
    auto uruguay = m_map->add_territory(south_america, "Uruguay");
    auto argentina = m_map->add_territory(south_america, "Argentina");
    auto colombia = m_map->add_territory(south_america, "Colombia");

    auto africa = m_map->add_continent("Africa");
    auto argelia = m_map->add_territory(africa, "Argelia");

    m_map->connect_territories(brazil, uruguay);
    m_map->connect_territories(brazil, argentina);
    m_map->connect_territories(brazil, argelia);
    m_map->connect_territories(brazil, colombia);



    connect(_scene, SIGNAL(nodeContextMenu(QGVNode*)), SLOT(nodeContextMenu(QGVNode*)));
    connect(_scene, SIGNAL(nodeDoubleClick(QGVNode*)), SLOT(nodeDoubleClick(QGVNode*)));
}

MainWindow::~MainWindow()
{
    delete ui;
    if(m_map)
        delete m_map;
}

void MainWindow::drawGraph()
{
    /*
    _scene->loadLayout("digraph test{node [style=filled,fillcolor=white];N1 -> N2;N2 -> N3;N3 -> N4;N4 -> N1;}");
    connect(_scene, SIGNAL(nodeContextMenu(QGVNode*)), SLOT(nodeContextMenu(QGVNode*)));
    connect(_scene, SIGNAL(nodeDoubleClick(QGVNode*)), SLOT(nodeDoubleClick(QGVNode*)));
    ui->graphicsView->setScene(_scene);
    return;
    */

    //Configure scene attributes
    _scene->setGraphAttribute("label", m_map->name().c_str());

    _scene->setGraphAttribute("splines", "ortho");
    _scene->setGraphAttribute("rankdir", "LR");
    //_scene->setGraphAttribute("concentrate", "true"); //Error !
    _scene->setGraphAttribute("nodesep", "0.4");

    _scene->setNodeAttribute("shape", "box");
    _scene->setNodeAttribute("style", "filled");
    _scene->setNodeAttribute("fillcolor", "white");
    _scene->setNodeAttribute("height", "1.2");
    _scene->setEdgeAttribute("minlen", "3");
    //_scene->setEdgeAttribute("dir", "both");

    //Add some nodes

    std::map<risk::map::continent::id, QGVSubGraph*> continents;
    std::map<risk::map::continent_territory_id, QGVNode*> nodes;
    std::map<std::string, QGVNode*> nodes_by_name;

    for(std::size_t i = 0; i < m_map->num_continents(); ++i)
    {
        QGVSubGraph *continent = _scene->addSubGraph(QString::fromStdString(m_map->get_continent(i).name()));
        continent->setAttribute("label", QString::fromStdString(m_map->get_continent(i).name()));
        continents[i] = continent;
        for(std::size_t j = 0; j < m_map->get_continent(i).num_territories(); ++j)
        {
            risk::map::continent_territory_id territory = {i, j};
            nodes[territory] = continent->addNode(QString::fromStdString(m_map->get_continent(i).get_territory(j).name()));
            nodes_by_name[m_map->get_continent(i).get_territory(j).name()] = nodes[territory];
        }
    }

    for(std::size_t i = 0; i < m_map->num_continents(); ++i)
    {
        for(std::size_t j = 0; j < m_map->get_continent(i).num_territories(); ++j)
        {
            risk::map::continent_territory_id territory = {i, j};
            for(std::size_t k = 0; k < m_map->num_neighbors(territory); ++k)
            {
                auto neighbor = m_map->get_neighbor(territory, k);
                _scene->addEdge(nodes[territory], nodes_by_name[neighbor.name()]);
            }
        }

    }

    //    QGVNode *node1 = _scene->addNode("BOX");
    //    node1->setIcon(QImage(":/icons/Gnome-System-Run-64.png"));
    //    QGVNode *node2 = _scene->addNode("SERVER0");
    //    node2->setIcon(QImage(":/icons/Gnome-Network-Transmit-64.png"));
    //    QGVNode *node3 = _scene->addNode("SERVER1");
    //    node3->setIcon(QImage(":/icons/Gnome-Network-Transmit-64.png"));
    //    QGVNode *node4 = _scene->addNode("USER");
    //    node4->setIcon(QImage(":/icons/Gnome-Stock-Person-64.png"));
    //    QGVNode *node5 = _scene->addNode("SWITCH");
    //    node5->setIcon(QImage(":/icons/Gnome-Network-Server-64.png"));

    //Add some edges
    //    _scene->addEdge(node1, node2, "TTL")->setAttribute("color", "red");
    //    _scene->addEdge(node1, node2, "SERIAL");
    //    _scene->addEdge(node1, node3, "RAZ")->setAttribute("color", "blue");
    //    _scene->addEdge(node2, node3, "SECU");

    //    _scene->addEdge(node2, node4, "STATUS")->setAttribute("color", "red");

    //    _scene->addEdge(node4, node3, "ACK")->setAttribute("color", "red");

    //    _scene->addEdge(node4, node2, "TBIT");
    //    _scene->addEdge(node4, node2, "ETH");
    //    _scene->addEdge(node4, node2, "RS232");

    //    _scene->addEdge(node4, node5, "ETH1");
    //    _scene->addEdge(node2, node5, "ETH2");



    //Layout scene
    _scene->applyLayout();

    //Fit in view
    ui->graphicsView->fitInView(_scene->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::nodeContextMenu(QGVNode *node)
{
    //Context menu exemple
    QMenu menu(node->label());

    menu.addSeparator();
    menu.addAction(tr("Informations"));
    menu.addAction(tr("Options"));

    QAction *action = menu.exec(QCursor::pos());
    if(action == 0)
        return;
}

void MainWindow::nodeDoubleClick(QGVNode *node)
{
    QMessageBox::information(this, tr("Node double clicked"), tr("Node %1").arg(node->label()));
}

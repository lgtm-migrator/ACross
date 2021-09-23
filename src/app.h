#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QFont>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringLiteral>
#include <QTranslator>
#include <QUrl>

#include "models/dbtools.h"
#include "models/envtools.h"
#include "view_models/configtools.h"
#include "view_models/grouplist.h"
#include "view_models/groupmodel.h"
#include "view_models/imageprovider.h"
#include "view_models/logview.h"
#include "view_models/nodeformmodel.h"
#include "view_models/nodelist.h"
#include "view_models/nodemodel.h"
#include "view_models/rawoutboundformmodel.h"
#include "view_models/shadowsocksformmodel.h"
#include "view_models/systemtray.h"
#include "view_models/trojanformmodel.h"
#include "view_models/urlschemeformmodel.h"
#include "view_models/vmessformmodel.h"

namespace across {
#define APP_NAME "ACross"

class Application : public QApplication
{
  Q_OBJECT
public:
  explicit Application(int& argc, char** argv);

  ~Application();

  int run();

  void setRootContext();

  void setTranslator(const QString& lang = "current");

  void registerModels();

  static void removeImageProvider(ImageProvider* img_provider);

private:
  QSharedPointer<LogView> p_logview;
  QSharedPointer<across::setting::ConfigTools> p_config;
  QSharedPointer<across::DBTools> p_db;
  QSharedPointer<across::core::CoreTools> p_core;
  QSharedPointer<across::network::CURLTools> p_curl;
  QSharedPointer<across::NodeList> p_nodes;
  QSharedPointer<across::GroupList> p_groups;
  QSharedPointer<across::SystemTray> p_tray;
  across::ImageProvider *p_image_provider;

  const QString m_app_name = APP_NAME;
  QTranslator m_translator;
  QQmlApplicationEngine m_engine;
};
}

#endif // APPLICATION_H

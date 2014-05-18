#ifndef COVERART_H
#define COVERART_H

#include <QObject>

#include "trackinfoobject.h"

class CoverArt : public QObject {
    Q_OBJECT
  public:
    CoverArt(ConfigObject<ConfigValue> *pConfig);
    virtual ~CoverArt();

    bool deleteFile(const QString& location);
    QString searchCoverArtFile(TrackInfoObject* pTrack);

  private:
    ConfigObject<ConfigValue>* m_pConfig;

    const char* m_cDefaultImageFormat;

    QString getStoragePath() const;
    bool saveFile(QImage cover, QString location);
    QString searchInDiskCache(QString coverArtName);
    QString searchInTrackDirectory(QString directory);
};

#endif // COVERART_H

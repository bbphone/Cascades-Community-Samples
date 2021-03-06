/* Copyright (c) 2013 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef APDU_DETAILS_h
#define APDU_DETAILS_h

#include <QtCore/QObject>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/Container>
#include <bb/cascades/Page>
#include <bb/system/SystemDialog.hpp>

#include "EventLog.hpp"

using namespace bb::cascades;

class ApduDetails: public QObject {

	Q_OBJECT
	Q_PROPERTY(QString _aid READ getAid WRITE setAid NOTIFY detectAidChanged)
	Q_PROPERTY(bool _select_only READ getSelectOnly WRITE setSelectOnly NOTIFY detectSelectOnlyChanged)
	Q_PROPERTY(bool _ppse READ getPpse WRITE setPpse NOTIFY detectPpseChanged)
	Q_PROPERTY(int _target_inx READ getTargetInx WRITE setTargetInx NOTIFY detectTargetInxChanged)
	Q_PROPERTY(QString _cla READ getCla WRITE setCla NOTIFY detectClaChanged)
	Q_PROPERTY(QString _ins READ getIns WRITE setIns NOTIFY detectInsChanged)
	Q_PROPERTY(QString _p1p2 READ getP1p2 WRITE setP1p2 NOTIFY detectP1p2Changed)
	Q_PROPERTY(QString _lc READ getLc WRITE setLc NOTIFY detectLcChanged)
	Q_PROPERTY(QString _command READ getCommand WRITE setCommand NOTIFY detectCommandChanged)
	Q_PROPERTY(QString _le READ getLe WRITE setLe NOTIFY detectLeChanged)

public:
	ApduDetails();
	virtual ~ApduDetails();

	QString getAid() const;
	void setAid(QString aid);
	bool getSelectOnly() const;
	void setSelectOnly(bool select_only);
	bool getPpse() const;
	void setPpse(bool ppse);
	int getTargetInx() const;
	void setTargetInx(int target_inx);
	QString getCla() const;
	void setCla(QString cla);
	QString getIns() const;
	void setIns(QString Ins);
	QString getP1p2() const;
	void setP1p2(QString p1p2);
	QString getLc() const;
	void setLc(QString lc);
	QString getCommand() const;
	void setCommand(QString command);
	QString getLe() const;
	void setLe(QString le);

private:
	QmlDocument* _qml;
	Page* _root;
	EventLog* _eventLog;
	QString _aid;
	QString _target;
	int _target_inx;
	bool _select_only;
	bool _ppse;
	QString _hex_cla;
	QString _hex_ins;
	QString _hex_p1p2;
	QString _hex_lc;
	QString _hex_command;
	QString _hex_le;

	bb::system::SystemDialog *_systemDialog;

	void findAndConnectControls();
	void createModules();
	void connectNavigationSignals();

public slots:
	void show();
	void startApduDetailsProcess();
	void onAidChanged(QString aid);
	void onSelectOnlyChanged(bool select_only);
	void onPpseChanged(bool ppse);
	void onTargetInxChanged(int target_inx);
	void onClaChanged(QString cla);
	void onInsChanged(QString ins);
	void onP1p2Changed(QString p1p2);
	void onLcChanged(QString lc);
	void onCommandChanged(QString command);
	void onLeChanged(QString le);
	void backFromEventLog();

signals:

	void back();
	void detectAidChanged();
	void detectSelectOnlyChanged();
	void detectPpseChanged();
	void detectTargetInxChanged();
	void detectClaChanged();
	void detectInsChanged();
	void detectP1p2Changed();
	void detectLcChanged();
	void detectCommandChanged();
	void detectLeChanged();
	void showEventLog();

};

#endif // ifndef APDU_DETAILS_h
